# 반복자를 이용한 연결 리스트
## 📢 개요

 **반복자(이터레이터;iterator)** 패턴은 집합체에 사용하면 몇가지 이점을 얻을 수 있다. 첫째로, 컬렉션을 iterator를 이용해 간접 접근하는 것이기 때문에 구현 방법을 노출시키지 않아(정보 은닉; information hiding) 모듈화하기 쉬워진다. 즉, 정보은닉을 하여 높은 응집도와 낮은 결합도를 얻는 것이다. 이로 인해서 코드에 문제가 발생했을 때 수정해야 하는 부분이 명확해지고 간결해진다.
 
 두번째로, 컬렉션 내부 구현에 대한 이해 없이도 그 집합체 내의 모든 항목에 접근할 수 있게 해주는 방법을 제공한다. 예를 들어서, array, list, hashtable, vector, set, map 등 각종 컨테이너들은 추가, 삽입, 검색, 삭제 등 항목에 대한 처리 방식이 모두 다르다. 이러한 *반복 작업*을 iterator 객체에 맡기면 인터페이스(=순수 가상 함수) 및 구현이 간단해진다. 실제로 iterator 패턴은 C++ STL의 iterator, java의 iterator 메소드 등으로 많이 사용되고 있다.

 
 ## 🅿 원리
 ### 1. 노드 추가
   
 
 #### ● 소스 코드
      void DoublyLinkedlist::push_front(char* szData)
      {
        stNODE *pNode = (stNODE*)malloc(sizeof(stNODE));

        memcpy(pNode->szData, szData, sizeof(pNode->szData));

        pNode->pPrev = &_Head;
        pNode->pNext = _Head.pNext;
        pNode->pPrev->pNext = pNode;
        pNode->pNext->pPrev = pNode;
      }

      void DoublyLinkedlist::push_back(char* szData)
      {
        stNODE *pNode = (stNODE*)malloc(sizeof(stNODE));

        memcpy(pNode->szData, szData, sizeof(pNode->szData));

        pNode->pPrev = _Tail.pPrev;
        pNode->pNext = &_Tail;
        pNode->pPrev->pNext = pNode;
        pNode->pNext->pPrev = pNode;
      }
 
 ### 2. 노드 제거
 
  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2969.png)

 **figure 8. Phase 1*

  삭제하려는 노드의 이전 노드(20)을 찾습니다.
  
  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2970.png)

 **figure 9. Phase 2*
  
  삭제하려는 노드(30)도 찾습니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2971.png)

 **figure 10. Phase 3*

  삭제하려는 노드의 다음 노드(40)도 찾습니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2972.png)

 **figure 11. Phase 4*

  30을 삭제합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2973.png)

 **figure 12. Phase 5*

  20의 다음 노드로 40을 지정합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2974.png)

 **figure 13. Phase 6*

  40의 이전 노드로 20을 지정합니다.

  ![](https://s3.ap-northeast-2.amazonaws.com/opentutorials-user-file/module/1335/2975.png)

 **figure 14. Phase 7*

  삭제가 완료 되었습니다.
 
 
  #### ● 소스 코드
      bool DoublyLinkedlist::Delete(char* szData)
      {
        stNODE *pNode = _Head.pNext;

        while (pNode->pNext != NULL)
        {
          if (strcmp(pNode->szData, szData) == 0)
          {
            pNode->pPrev->pNext = pNode->pNext;
            pNode->pNext->pPrev = pNode->pPrev;
            free(pNode);
            return true;
          }
          pNode = pNode->pNext;
        }
        return false;
      }
 
 
 ## 📌 이미지 및 설명 출처 
 
 원리 파트 - https://opentutorials.org/module/1335/8940



