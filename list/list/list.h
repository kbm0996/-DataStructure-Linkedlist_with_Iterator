#ifndef __LIST_H__
#define __LIST_H__

namespace mylib
{
	template <typename T>
	class list
	{
	public:
		struct Node
		{
			T _Data;
			Node *_pPrev;
			Node *_pNext;
		};

		class iterator
		{
		private:
			Node *_pNode;
		public:
			iterator(Node *node = nullptr)
			{
				_pNode = node;
			}

			iterator operator ++(int)
			{
				iterator temp = _pNode;
				_pNode = _pNode->_pNext;
				return temp;
			}
			iterator operator ++()
			{
				_pNode = _pNode->_pNext;
				return *this;
			}
			iterator operator --(int)
			{
				iterator temp = _pNode;
				_pNode = _pNode->_pPrev;
				return *this;
			}

			iterator operator --()
			{
				_pNode = _pNode->_pPrev;
				return *this;
			}

			T& operator *()
			{
				return _pNode->_Data;
			}

			bool operator !=(iterator& iter)
			{
				return _pNode != iter._pNode;
			}

			bool operator ==(iterator& iter)
			{
				return _pNode == iter._pNode;
			}

			Node* getNode()
			{
				return this->_pNode;
			}
		};

	public:
		list() :_iSize(0)
		{
			_Head._Data = 0;
			_Head._pPrev = nullptr;
			_Head._pNext = &_Tail;
			_Tail._Data = 0;
			_Tail._pPrev = &_Head;
			_Tail._pNext = nullptr;
		}

		~list()
		{
		}

		iterator begin()
		{
			iterator begin(_Head._pNext);
			return begin;
		}
		iterator end()
		{
			iterator end(&_Tail);
			return end;
		}

		void push_front(T data)
		{
			Node *pNode = new Node;

			pNode->_Data = data;
			_iSize++;

			pNode->_pPrev = &_Head;
			pNode->_pNext = _Head._pNext;
			pNode->_pPrev->_pNext = pNode;
			pNode->_pNext->_pPrev = pNode;
		}

		void push_back(T data)
		{
			Node *pNode = new Node;

			pNode->_Data = data;
			_iSize++;

			pNode->_pPrev = _Tail._pPrev;
			pNode->_pNext = &_Tail;
			pNode->_pPrev->_pNext = pNode;
			pNode->_pNext->_pPrev = pNode;
		}

		void pop_front()
		{
			Node *pNode = _Head._pNext;

			if (pNode != &_Tail)
			{
				pNode->_Data = 0;
				_iSize--;

				pNode->_pNext->_pPrev = &_Head;
				pNode->_pPrev->_pNext = pNode->_pNext;
				delete(pNode);
			}
		}

		void pop_back()
		{
			Node *pNode = _Tail._pPrev;

			if (pNode != &_Head)
			{
				pNode->_Data = 0;
				_iSize--;

				pNode->_pNext->_pPrev = pNode->_pPrev;
				pNode->_pPrev->_pNext = &_Tail;
				delete(pNode);
			}
		}

		void sort()
		{
			Node *pNode = _Head._pNext;
			Node *pPrev;
			T TempData;
			while (pNode->_pNext != nullptr)
			{
				pPrev = &_Head;
				while (pPrev != pNode)
				{
					if (pPrev != &_Head)
					{
						if (pPrev->_Data > pNode->_Data)
						{
							TempData = pPrev->_Data;
							pPrev->_Data = pNode->_Data;
							pNode->_Data = TempData;
						}
					}
					pPrev = pPrev->_pNext;
				}
				pNode = pNode->_pNext;
			}
		}

		void clear()
		{
			while (_iSize != 0)
				pop_front();
		}

		int size()
		{
			return _iSize;
		}
		bool empty()
		{
			if (_iSize == 0)
				return true;
			return false;
		}

		iterator erase(iterator iter)
		{
			iterator temp = iter;
			Node *pNode = temp.getNode();
			++temp;

			pNode->_Data = 0;
			pNode->_pNext->_pPrev = pNode->_pPrev;
			pNode->_pPrev->_pNext = pNode->_pNext;
			delete(pNode);

			return temp;
		}

	private:
		int _iSize;
		Node _Head;
		Node _Tail;
	};
}
#endif