#pragma once
#pragma once

#include <algorithm>
#include <new>

template <typename T>
class CMyArray
{
public:
	CMyArray() = default;

	CMyArray(const CMyArray& arr)
	{
		const auto size = arr.GetSize();
		if (size != 0)
		{
			m_begin = RawAlloc(size);
			try
			{
				CopyItems(arr.m_begin, arr.m_end, m_begin, m_end);
				m_endOfCapacity = m_end;
			}
			catch (...)
			{
				DeleteItems(m_begin, m_end);
				throw;
			}
		}
	}

	void Append(const T& value)
	{
		if (m_end == m_endOfCapacity) // no free space
		{
			size_t newCapacity = std::max(size_t(1), GetCapacity() * 2);

			auto newBegin = RawAlloc(newCapacity);
			T* newEnd = newBegin;
			try
			{
				CopyItems(m_begin, m_end, newBegin, newEnd);
				// ������������ ����� value �� ������ newItemLocation
				new (newEnd) T(value);
				++newEnd;
			}
			catch (...)
			{
				DeleteItems(newBegin, newEnd);
				throw;
			}
			DeleteItems(m_begin, m_end);

			// ������������� �� ������������� ������ ��������� ���������
			m_begin = newBegin;
			m_end = newEnd;
			m_endOfCapacity = m_begin + newCapacity;
		}
		else // has free space
		{
			new (m_end) T(value);
			++m_end;
		}
	}

	T& GetBack()
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	const T& GetBack() const
	{
		assert(GetSize() != 0u);
		return m_end[-1];
	}

	size_t GetSize() const
	{
		return m_end - m_begin;
	}

	size_t GetCapacity() const
	{
		return m_endOfCapacity - m_begin;
	}

	/*
	����������� ������������� ���������������� ������� � ��������� ������� ��� ������ ��������� �[]�.� ������,
	���� ������ �������� ������� �� ������� �������, ������ ������������� ���������� std::out_of_range
	*/

	T& operator[](size_t index)
	{
		size_t Size = GetSize();
		if (index >= GetSize())
		{
			throw std::out_of_range("index out of range");
		}

		return m_begin[index];
	}

	T const& operator[](size_t index) const
	{
		size_t Size = GetSize();
		if (index >= Size)
			throw std::out_of_range("Index is out of range");
		return m_begin[index];
	}

	/*
	����������� ��������� ����� ������� ��� ������ ������ Resize().� ������, ���� ����� ����� ������� 
	������ �������, ����������� � ����� ������� �������� ������ ������������������ ��������� �� ��������� ��� ���� T.
	*/
	/*
	void Resize(const size_t& newSize)
	{
		size_t size = GetSize();
		if (size > newSize)
		{
			m_end = m_end - (size - newSize);
		}
		else if (size < newSize)
		{
			m_end = m_end + (newSize - m_end)
		}
	}
	*/
	void Clear() noexcept
	{
		DestroyItems(m_begin, m_end);
		m_end = m_begin;
	}

	~CMyArray()
	{
		DeleteItems(m_begin, m_end);
	}

private:
	static void DeleteItems(T* begin, T* end)
	{
		// ��������� ������ ��������
		DestroyItems(begin, end);
		// ����������� ������� ������ ��� �� ��������
		RawDealloc(begin);
	}

	// �������� �������� �� �������� ������� � to, ���������� newEnd
	static void CopyItems(const T* srcBegin, T* srcEnd, T* const dstBegin, T*& dstEnd)
	{
		for (dstEnd = dstBegin; srcBegin != srcEnd; ++srcBegin, ++dstEnd)
		{
			// Construct "T" at "dstEnd" as a copy of "*begin"
			new (dstEnd) T(*srcBegin);
		}
	}

	static void DestroyItems(T* from, T* to)
	{
		// dst - ����� ������, ��� ��������������� �������� ���� ��������� ����������
		// to - ������ ������������������ ������
		while (to != from)
		{
			--to;
			// ���� �������� ���������� ��� ���������� ���� T
			to->~T();
		}
	}

	static T* RawAlloc(size_t n)
	{
		size_t memSize = n * sizeof(T);
		T* p = static_cast<T*>(malloc(memSize));
		if (!p)
		{
			throw std::bad_alloc();
		}
		return p;
	}

	static void RawDealloc(T* p)
	{
		free(p);
	}

private:
	T* m_begin = nullptr;
	T* m_end = nullptr;
	T* m_endOfCapacity = nullptr;
};
