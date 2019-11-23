(define (enum-interval start end)
	(cond ((>= start end) '())
		((equal? (remainder start 2) 0) 
			(cons start (enum-interval (+ 1 start) end)))
		(else (enum-interval (+ 1 start) end))
	)
)

; (enum-interval 1 10)

; calculate x^y
(define (power x y)
    (cond ((equal? y 0) 1)
	    (else (* x (power x (- y 1))))
    )
)
; (power 2 3) => 8


(define (fib-squares num)
	(cond ((equal? num 0) '(0))
		((equal? num 1) '(0 1))
		(else (append (fib-squares (- num 1)) 
				(list (inexact->exact (power (round (/ (power (/ (+ 1 (sqrt 5)) 2) num) (sqrt 5))) 2)))
			)
		)
	)
)

; (fib-squares 10)

; note fibb. number = round(pow((1 + sqrt(5)) / 2, n) / sqrt(5)) 
