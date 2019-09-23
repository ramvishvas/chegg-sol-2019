(define (number-list? L)
	; if null considern valid
	(cond ((null? L) #t)
		; check is 1st element is number
		; if not return #f
		((not (number? (car L))) #f)
		; else check remaining element
		(else (number-list? (cdr L)))))

; (number-list? '(1 2 3 4))
; (number-list? '(1 2 (3) 4))
; (number-list? '(1 2 a 4))

; it will give you sum of a valid number list
(define (sum L)
	; if list is null return 0
	(cond ((null? L) 0)
		; else add 1st number with remaining number list
		(else (+ (car L) (sum (cdr L))))))

(define (sum-num-list L)
	; if null return #f you canreturn #t also
	(cond ((null? L) #f)
		; chech is list contain only number
		; if not return #f
		((not (number-list? L)) #f)
		; else return sum
		(else (sum L))))

; (sum-num-list '(1 2 3 4 5))
; (sum-num-list '(1 (2)))
; (sum-num-list '(a b c))