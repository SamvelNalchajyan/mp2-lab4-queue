#pragma once

template <class T>
class TQueue
{
private:
	T* mas;
	int CurrSize;
	int MaxSize;
	int Head;
	int Tail;
public:
	TQueue(int _MaxSize = 30);
	TQueue(const TQueue<T>& q);
	~TQueue();

	int GetCurrSize();
	int GetMaxSize();
	int GetHead();
	TQueue<T>& operator=(const TQueue<T>& q);
	bool IsEmpty();
	bool IsFull();
	void Push(const T& a);
	T Pop();
	T Front();
	T Back();
};

template <class T>
TQueue<T>::TQueue(int _MaxSize)
{
	MaxSize = _MaxSize;
	mas = new T[MaxSize];
	Head = 0;
	Tail = -1;
	CurrSize = 0;
}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& q)
{
	MaxSize = q.MaxSize;
	mas = new T[MaxSize];
	CurrSize = q.CurrSize;
	Head = q.Head;
	Tail = q.Tail;
	for (int i = 0; i < CurrSize; i++)
	{
		mas[i] = q.mas[i];
	}
}

template <class T>
TQueue<T>::~TQueue()
{
	delete[] mas;
}

template <class T>
int TQueue<T>::GetCurrSize()
{
	return CurrSize;
}

template <class T>
int TQueue<T>::GetMaxSize()
{
	return MaxSize;
}

template <class T>
int TQueue<T>::GetHead()
{
	return Head;
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
{
	if (this != &q)
	{
		if (MaxSize != q.MaxSize)
		{
			MaxSize = q.MaxSize;
			delete[] mas;
			mas = new T[MaxSize];
		}
		CurrSize = q.CurrSize;
		Head = q.Head;
		Tail = q.Tail;
		if (Head <= Tail)
		{
			for (int i = Head; i <= Tail; i++)
			{
				mas[i] = q.mas[i];
			}
		}
		else
		{
			for (int i = Head; i < MaxSize; i++)
			{
				mas[i] = q.mas[i];
			}
			for (int i = 0; i <= Tail; i++)
			{
				mas[i] = q.mas[i];
			}
		}
	}
	return *this;
}

template <class T>
bool TQueue<T>::IsEmpty()
{
	return !CurrSize;
}

template <class T>
bool TQueue<T>::IsFull()
{
	return CurrSize == MaxSize;
}

template <class T>
void TQueue<T>::Push(const T& a)
{
	if (IsFull())
	{
		throw 1;
	}
	if (Tail != MaxSize - 1)
	{
		Tail++;
	}
	else
	{
		Tail = 0;
	}
	CurrSize++;
	mas[Tail] = a;
}

template <class T>
T TQueue<T>::Pop()
{
	if (IsEmpty())
	{
		throw 2;
	}
	int pos = Head;
	if (Head != MaxSize - 1)
	{
		Head++;
	}
	else
	{
		Head = 0;
	}
	CurrSize--;
	return mas[pos];
}

template <class T>
T TQueue<T>::Front()
{
	if (IsEmpty())
	{
		throw 3;
	}
	return mas[Head];
}

template <class T>
T TQueue<T>::Back()
{
	if (IsEmpty())
	{
		throw 3;
	}
	return mas[Tail];
}