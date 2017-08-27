package odd_even_linked_list

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func oddEvenList(head *ListNode) *ListNode {
	var oddHead, evenHead *ListNode
	var oddTail, evenTail *ListNode

	cnt := 1
	for head != nil {
		if cnt%2 == 1 {
			if oddHead == nil {
				oddHead = head
				oddTail = oddHead
			} else {
				oddTail.Next = head
				oddTail = head
			}
		} else {
			if evenHead == nil {
				evenHead = head
				evenTail = evenHead
			} else {
				evenTail.Next = head
				evenTail = head
			}
		}

		cnt++
		head = head.Next
	}

	if oddHead != nil {
		if evenTail != nil {
			evenTail.Next = nil
		}
		oddTail.Next = evenHead
	}

	return oddHead
}
