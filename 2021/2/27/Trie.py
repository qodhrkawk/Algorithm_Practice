#프로그래머스 가사 검색
from _collections import defaultdict
import sys
sys.setrecursionlimit(100001)

class Node :
    def __init__(self,key,passedNum = None,data = None):
        self.key = key
        self.data = None
        # self.isEnd = False
        self.passedNum = defaultdict(int)
        self.children = {}



class Trie :
    def __init__(self):
        self.head = Node(None)


    def insert(self,str):
        curr_node = self.head
        curr_node.passedNum[len(str)] += 1
        for char in str :
            if char not in curr_node.children :
                curr_node.children[char] = Node(char)
            curr_node.children[char].passedNum[len(str)] += 1
            curr_node = curr_node.children[char]


        curr_node.data = str

    # def search(self,str):
    #     curr_node = self.head
    #
    #     for char in str :
    #         if char in curr_node.children :
    #             curr_node = curr_node.children[char]
    #         else :
    #             return False
    #
    #     if curr_node.isEnd  :
    #         return True

    def problem_search(self,query,n):
        curr_node = self.head
        for q in query :
            if q in curr_node.children :
                curr_node = curr_node.children[q]
            else :
                return 0

        return curr_node.passedNum[n]




    # def starts_with(self,prefix,n):
    #     curr_node = self.head
    #     result = 0
    #     subtrie = None
    #
    #     for char in prefix :
    #         if char in curr_node.children :
    #             curr_node = curr_node.children[char]
    #             subtrie = curr_node
    #         else :
    #             return 0
    #
    #     queue = list(subtrie.children.values())
    #
    #     while queue :
    #         curr = queue.pop()
    #         if curr.data != None and len(curr.data) == n:
    #             result += 1
    #
    #         queue += list(curr.children.values())
    #
    #     return result



def solution(words, queries):
    answer = []


    # dic = {}


    trie1 = Trie()
    trie2 = Trie()

    for w in words:
        trie1.insert(w)
        trie2.insert(w[::-1])


    for q in queries :
        n = len(q)
        if q[0] == '?' and q[-1] == '?' :
            answer.append(trie1.head.passedNum[len(q)])
            continue

        # if q in dic :
        #     answer.append(dic[q])
        #     continue

        if q[0] == '?' :
            prefix = q[::-1].split("?")[0]
            answer.append(trie2.problem_search(prefix,n))
            # dic["q"] = res


        else :
            prefix = q.split("?")[0]
            answer.append(trie1.problem_search(prefix,n))
            # dic["q"] = res

    return answer
