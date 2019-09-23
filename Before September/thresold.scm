(define (threshold lst n)
	; check is list null
    (cond ((null? lst) '())
    	; if 1st number is less then add it to list and call function 
    	; again with remaining list
        ((< (car lst) n) (cons (car lst) (threshold (cdr lst) n)))
        ; if number is grater skip it
        (else (threshold (cdr lst) n))))

; (threshold '(3 6.2 7 2 9 5.3 1) 6)
; (threshold '(1 2 3 4 5) 4)
; (threshold '(4 8 5 6 7) 6.1)
; (threshold '(8 3 5 7) 2)
