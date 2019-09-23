(define (egyption-fraction n)
	; if number is invalid
	(cond ((or (<= n 0) (equal? 0 (numerator n)) (equal? 0 (denominator n))) '())
		; if number is = 1/2
		((= n (/ 1 2)) (cons (/ 1 3) (egyption-fraction (- n (/ 1 3)))))
		; if number is > 1/2
		((> n (/ 1 2)) (cons (/ 1 2) (egyption-fraction (- n (/ 1 2)))))
		; if number is < 1/2
		(else (cons (/ 1 (ceiling (/ (denominator n) (numerator n)))) 
		(egyption-fraction (- n (/ 1 (ceiling (/ (denominator n) (numerator n))))))))))

; (egyption-fraction 1)
; (egyption-fraction (/ 5 7))


; bonus quesstion
; to check list is descending or not
(define (is-order-valid? L)
	; if list is null and return false
	(cond ((null? L) #f)
		; if list has only one element
		((null? (cdr L)) 
			; check if it a valid or not
			(cond ((and (equal? 1 (numerator (car L)))
				(not (equal? 1 (denominator (car L))))) #t)
				; if not valid
				(else #f)))
		; if 1st number is less than equal to 2nd 
		; or numerator not equal to 1 or denominator equal to 1
		((or (<= (car L) (cadr L)) 
			(not (equal? 1 (numerator (car L))))
			(not (equal? 1 (numerator (cadr L))))
			(equal? 1 (denominator (car L)))
			(equal? 1 (denominator (cadr L)))) #f)
		; else iterate to remaining list
		(else (is-order-valid? (cdr L)))))

; get sum of list 
(define (sum L)
	; if list is empty return 0
	(cond ((null? L) 0)
		; add 1t number to the ssum of remaining list
		(else (+ (car L) (sum (cdr L))))))


(define (egyptian? L n)
	; check if list is empty
	(cond ((null? L) #false)
		; verify valid condition
		((and (equal? (sum L) n) (is-order-valid? L)) #true)
		; else return false
		(else #false)))













(define (egyption-fraction n)
(cond ((or (<= n 0) (equal? 0 (numerator n)) (equal? 0 (denominator n))) '())
((= n (/ 1 2)) (cons (/ 1 3) (egyption-fraction (- n (/ 1 3)))))
((> n (/ 1 2)) (cons (/ 1 2) (egyption-fraction (- n (/ 1 2)))))
(else (cons (/ 1 (ceiling (/ (denominator n) (numerator n)))) 
(egyption-fraction (- n (/ 1 (ceiling (/ (denominator n) (numerator n))))))))))

; (egyption-fraction 1)
; (egyption-fraction (/ 5 7))
