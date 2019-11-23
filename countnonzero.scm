; return list of positive number
; (posOnly '(-1 1 2 0 3 4 -4 5)) =? (1 2 3 4 5)
(define (posOnly lst)
	(cond ((null? lst) '())
		((< (car lst) 1) (posOnly (cdr lst)))
		(else (cons (car lst) (posOnly (cdr lst))))
	)
)

; this function will count 0 in list
; (countZero '(-1 1 2 0 3 4 -4 5)) => 1
; (countZero '(-9 2 3 0 -2 -8 0)) => 2
(define (countZero lst)
	(cond ((null? lst) 0)
		((equal? (car lst) 0) (+ 1 (countZero (cdr lst))))
		(else (countZero (cdr lst)))
	)
)

; this function will count positive in list
; (countPos '(-1 1 2 0 3 4 -4 5)) => 5
; (countPos '(-9 2 3 0 -2 -8 0)) => 2
(define (countPos lst)
	(cond ((null? lst) 0)
		((> (car lst) 0) (+ 1 (countPos (cdr lst))))
		(else (countPos (cdr lst)))
	)
)

; this function will count negative in list
; (countNeg '(-1 1 2 0 3 4 -4 5)) => 2
; (countNeg '(-9 2 3 0 -2 -8 0)) => 3
(define (countNeg lst)
	(cond ((null? lst) 0)
		((< (car lst) 0) (+ 1 (countNeg (cdr lst))))
		(else (countNeg (cdr lst)))
	)
)

; required function
; (zeroPosNeg '(-1 1 2 0 3 4 -4 5)) => '(1 5 2)
; (zeroPosNeg '(-9 2 3 0 -2 -8 0)) => '(2 2 3)
(define (zeroPosNeg lst)
	(cond ((null? lst) '())
		(else (list (countZero lst) (countPos lst) (countNeg lst)))
	)
)