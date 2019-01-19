# 반복자를 이용한 연결 리스트
## 📢 개요

 **반복자(이터레이터;iterator)** 패턴은 집합체에 사용하면 대표적으로  가지 이점을 얻을 수 있다.
 
 첫째로, 컬렉션을 iterator를 이용해 간접 접근하는 것이기 때문에 구현 방법을 노출시키지 않아(정보 은닉; information hiding) 모듈화하기 쉬워진다. 즉, 정보은닉을 하여 높은 응집도와 낮은 결합도를 얻는 것이다. 이로 인해서 코드에 문제가 발생했을 때 수정해야 하는 부분이 명확해지고 간결해진다.
 
 두번째로, 컬렉션 내부 구현에 대한 이해 없이도 그 집합체 내의 모든 항목에 접근할 수 있게 해주는 방법을 제공한다. 예를 들어서, array, list, hashtable, vector, set, map 등 각종 컨테이너들은 추가, 삽입, 검색, 삭제 등 항목에 대한 처리 방식이 모두 다르다. 이러한 *반복 작업*을 iterator 객체에 맡기면 인터페이스(=순수 가상 함수) 및 구현이 간단해진다. 실제로 iterator 패턴은 C++ STL의 iterator, java의 iterator 메소드 등으로 많이 사용되고 있다.

 
 ## 🅿 주요 소스 코드
 
 ![](https://github.com/kbm0996/Linkedlist_with_iterator/blob/master/capture.jpg?raw=true)
 
 **figure 1. 예제 프로그램 실행 화면*
 
 ### ● class list
 아래 코드 이외 DoublyLinkedlist와 동일
 
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
 
 ### ● class iterator (inner class of list)
  연산자 오버로딩을 이용해 컨테이너를 제어하는 클래스
  
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




