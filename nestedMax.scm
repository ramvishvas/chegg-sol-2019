
(define (findMax l)
	(cond ((null? l) 0)
		; check if only one element in list
		((null? (cdr l)) 
			; again check if that one element is list
			(cond ((list? (car l)) (findMax (car l)))
				; if that one element is not a list
				(else (car l))
			)
		)
		; if 1st element is list
		((list? (car l)) (findMax (append (car l) (cdr l))))
		; if 2nd element is list
		((list? (cadr l)) (findMax (cons (car l) (append (cadr l) (cddr l)))))
		; if 1st and 2nd are not list and 1st one is bigger
		((> (car l) (cadr l)) (findMax (cons (car l) (cddr l))))
		; if 1st and 2nd are not list and 2nd one is bigger
		(else (findMax (cdr l)))
	)
)

; (findMax '(4 5 1))
; (findMax '(5 2 (2 (4 8))))
; (findMax '(2 3 (3 3) () 6 (1)))