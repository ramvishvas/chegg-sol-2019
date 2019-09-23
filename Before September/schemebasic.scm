; this will reverse the list
(define (reverse lst)
    (cond ((null? lst) lst)
        (append (reverse (cdr lst)) (list (car lst)))))

; this will conver a number to list of digit
(define (number->list num)
  (map (lambda (c) (- (char->integer c) (char->integer #\0)))
       (string->list
        (number->string num))))

; check 10s column is zero or not
(define (isTensZero L)
	(cond ((null? L) '())
		((null? (cdr L)) '())
		((eq? (car (cdr L))) #t)
		(else #f)))

; return lisst of required number
(define (zero-ten L) 
	(cond ((null? L) '())
		((isTensZero (reverse (number->list (car L)))) (append (car L) (zero-ten (cdr L))))
		(else (zero-ten (cdr L)))))