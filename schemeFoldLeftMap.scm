
; Fold-left
(define (newlength list)
  (fold-left (lambda (sum element) (+ sum 1)) 0 list))

; (newlength '())
; (newlength '(1 2 3))
; (newlength '(3 (5 3) (7 (7) 7) 9))

; using map
(define (addOne l)
	(cond ((null? l) '())
		(else (map (lambda (n) (+ 1 n)) l))
	)
)
; (addOne '(1 2 3 4))
; (addOne '(2 4 6 8))
; (addOne '())


(define (lstOR items)
  	(car (fold-left (lambda (x y) 
  			; look for 1st #t if found then dont update the next list
			(cond ((and (equal? y (car x)) (equal? (car x) #f)) x)
				(else (list #t)))) '(#f) items)))

; (lstOR '(#t #f))
; (lstOR '(#f #f))
; (lstOR '())


; discard the same number and store it in liverse order and hen again reverse it
(define (removeDup items)
  	(fold-left (lambda (x y) (cons y x)) '()
		(fold-left (lambda (x y) 
			(cond ((null? x) (cons y x))
 				((equal? y (car x)) x)
				(else (cons y x)))) '() items)))

; (removeDup '(1 1 2))
; (removeDup '(3 5 5 7 7 7 9))
; (removeDup '())
