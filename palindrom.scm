(define (palindrom lst)
	(cond ((null? lst) #f)
		((equal? lst (reverse lst)) #t)
		(else #f)
	)
)

; (palindrom '(1 2 3 4 5))
; (palindrom '(1 2 3 4 5 4 3 2 1))