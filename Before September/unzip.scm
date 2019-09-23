
(define (get-first-list L)
	; if list is null
	(cond ((null? L) '())
		; get list of 1st element of List
		(else (cons (car (car L)) (get-first-list (cdr L))))))

(define (get-second-list L)
	; if list is null
	(cond ((null? L) '())
		; get list of 2st element of List
		(else (cons (car (cdr (car L))) (get-second-list (cdr L))))))

(define (unzip L)
	; if list is null
	(cond ((null? L) '())
		; appent 1st and 2nd list
		(else (append (get-first-list L) (get-second-list L)))))

(unzip '((1 2) (3 4) (5 6) (7 8)))