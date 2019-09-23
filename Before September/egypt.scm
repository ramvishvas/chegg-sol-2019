
(define (skip-sum L)
	; check if list is null
	(cond ((null? L) 0)
		; check if list has only one or two element
		((or (null? (cdr L)) (null? (cddr L))) (car L))
		; else add number to the result of remaining list,
		; by skiping next number
		(else (+ (car L) (skip-sum (cddr L))))))

; (skip-sum '(2 3 5))
; (skip-sum '(2 3 5 7))
; (skip-sum '(2 3 5 7 11))

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











(define (skip-sum L)
; check if list is null
(cond ((null? L) 0)
; check if list has only one or two element
((or (null? (cdr L)) (null? (cddr L))) (car L))
; else add number to the result of remaining list,
; by skiping next number
(else (+ (car L) (skip-sum (cddr L))))))













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
