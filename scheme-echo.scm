; (echo '(a b c)) => (a a b b c c)
; (echo '(a (b c))) => (a a (b c) (b c))
(define (echo lst)
	(cond ((null? lst) '())
		(else (append (list (car lst) (car lst)) 
			(echo (cdr lst)))
		)
	)
)


; (echo-lots-help 'x' 2) => (x x)
; (echo-lots-help 'x' 4) => (x x x x)
(define (echo-lots-help element n)
	(cond ((equal? n 0) '())
		(else (cons element (echo-lots-help element (- n 1))))
	)
)


; (echo-lots '(a (b c)) 3) => (a a a (b c) (b c) (b c))
(define (echo-lots lst n)
	(cond ((null? lst) '())
		(else (append (echo-lots-help (car lst) n) (
			echo-lots (cdr lst) n))
		)
	)
)


; (echo-all '(a (b c))) => (a a (b b c c)(b b c c)).
(define (echo-all lst)
	(cond ((null? lst) '())
		((list? (car lst)) (list (echo-all (car lst)) 
			(echo-all (car lst)))
		)
		(else (append (list (car lst) (car lst)) 
			(echo-all (cdr lst)))
		)
	)
)

; (nth 0 '(a b c)) => a
; (nth 1 '(a (b c) d)) => (b c)
(define (nth i lst)
	(cond ((equal? i 0) (car lst))
		(else (nth (- i 1) (cdr lst)))
	)
)