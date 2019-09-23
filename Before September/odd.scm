(define (odd-numbers l)
	; check if list is empty
	(cond ((null? l) '())
		; check if 1st number of list is even
		; and if its even then skip that number
		; and find odd in remaining
		((even? (car l)) (odd-numbers (cdr l)))
		; if 1st number of list is not even ie odd
		; then add that to "new list" with remaining odd of "original list"
		(else (cons (car l) (odd-numbers (cdr l))))
	)
)

; Note: "even?" is in-build function

; (odd-numbers '(2 4 9 16 25 7))