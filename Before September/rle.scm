; it will take a number, list, initialcount and 
; return continuous count of given number in given list from starting 
; (count 1 '(1 1 1 1 2 2 2 2 3 3 3 4 4 4) 0) ->  4
; (count 2 '(1 1 1 1 2 2 2 2 3 3 3 4 4 4) 0) ->  0
; (count 5 '(1 1 1 1 2 2 2 2 3 3 3 4 4 4) 0) ->  0
(define (count num lst initialcount)
	(cond ((null? lst)  initialcount)
		((equal? num (car lst)) (count num (cdr lst) (+ 1 initialcount)))
		(else initialcount)))

; it will take a list and a number(n) and
; it will skip 1st n element from give list
; (newlist 1 '(1 1 1 1 2 2 2 2 3 3 3 4 4 4)) ->  '(1 1 1 2 2 2 2 3 3 3 4 4 4)
; (newlist 2 '(1 1 1 1 2 2 2 2 3 3 3 4 4 4)) ->  '(1 1 2 2 2 2 3 3 3 4 4 4)
; (newlist 5 '(1 1 1 1 2 2 2 2 3 3 3 4 4 4)) ->  '(2 2 2 3 3 3 4 4 4)
(define (newlist n s)
	(cond ((null? s) '())
		((equal? 0 n) s)
		(else (newlist (- n 1) (cdr s)))))

; required function
; (rle '(1 1 1 1 2 2 2 2 3 3 3 4 4 4))
(define (rle s)
	(cond ((null? s) '())
		(else (cons (list (car s) (count (car s) s 0)) 
			(rle (newlist (count (car s) s 0) s))))))