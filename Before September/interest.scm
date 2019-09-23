(define (interest b r period)
	(cond ((equal? period 0) b)
		;  if period is not 0
		(else (interest (+ b (* b r)) r (- period 1)))
	)
)

; (interest 100 10 1)
; (interest 100 10 2)


(define (power b x)
	(cond ((equal? x 0) 1)
		; when x is even
		((even? x) (* (power b (/ x 2)) (power b (/ x 2))))
		; when x is oddd
		(else (* b (* (power b (/ (- x 1) 2)) (power b (/ (- x 1) 2)))))
	)
)

; (power 2 3)
