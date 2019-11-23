(define (merge-list lst1 lst2)
	(cond ((and (null? lst1) (null? lst2)) '())
		((null? lst1) lst2)
		((null? lst2) lst1)

		; if both is number
		((and (number? (car lst1)) (number? (car lst2)) (> (car lst1) (car lst2))) 
			(cons (car lst2) (merge-list lst1 (cdr lst2))))

		; if 1st is number and 2nd is not 
		((and (number? (car lst1)) (string>? (car (number->string lst1)) (car lst2))) 
			(cons (car lst2) (merge-list lst1 (cdr lst2))))

		; if 1st is number and 2nd is not number
		((and (number? (car lst2)) (> (car lst1) (car (number->string lst2)))) 
			(cons (car lst2) (merge-list lst1 (cdr lst2))))



		(else (cons (car lst1) (merge-list (cdr lst1) lst2)))
	)
)

; (merge-list '(1 5) '(2 3 4))
; (merge-list '(a s u x) '(b d g)