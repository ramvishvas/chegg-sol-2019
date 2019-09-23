(define (numbers x y)
	; if both equals then return list of y
	(cond ((equal? x y) (list y))
		; if x > y then return a list from y to x
		((> x y) (cons y (numbers (+ y 1) x)))
		; else return a list from x to y
		(else (cons x (numbers (+ x 1) y)))
	)
)

; (numbers 10 20)