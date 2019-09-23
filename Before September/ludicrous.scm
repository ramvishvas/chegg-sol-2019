(define (is-all-digit-even n)
	; check if number is less than 0
	(cond ((< n 0) #f)
		; check if number is single digit
		((and (>= n 0) (<= n 9) (even? n)) #t)
		; if last digit of n is odd
		((odd? (modulo n 10)) #f)
		; check for new number removing last digit
		(else (is-all-digit-even (quotient n 10)))))

(define (is-all-digit-odd n)
	; check if number is less than 0
	(cond ((< n 0) #f)
		; check if number is single digit
		((and (>= n 0) (<= n 9) (odd? n)) #t)
		; if last digit of n is even
		((even? (modulo n 10)) #f)
		; check for new number removing last digit
		(else (is-all-digit-odd (quotient n 10)))))


(define (ludicrous x)
	; check is all digit even
	(cond ((is-all-digit-even x) #t)
		; check is all digit odd
		((is-all-digit-odd x) #t)
		; else return false
		(else #f)))