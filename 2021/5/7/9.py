class Node:
    def __init__(self, data):
        self.data = data
        self.count = 0
        self.child = {}


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        cur = self.head
        cur.count += 1
        for c in string:
            if c not in cur.child:
                cur.child[c] = Node(c)
            cur = cur.child[c]
            cur.count += 1

    def count(self, prefix):
        cur = self.head

        for c in prefix:
            if c not in cur.child:
                return 0
            cur = cur.child[c]

        return cur.count

    def find(self,prefix):
        cur = self.head
        ans = 0
        for c in prefix:
            if cur.count == 1 :
                return ans

            cur = cur.child[c]
            ans += 1

        return ans


def solution(words):
    answer = 0
    trie = create_trie(words)

    for word in words:
        answer += count_matched_word(trie, word)

    return answer


def create_trie(words):
    trie = Trie()

    for word in words:
        trie.insert(word)

    return trie


def count_matched_word(trie, word):

    return trie.find(word)


print(solution(["go","gone","guild"]))