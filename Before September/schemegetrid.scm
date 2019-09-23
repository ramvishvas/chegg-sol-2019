; this is helper function
(define (remove-last L)
	; if list is null or hasonly one element
	(cond ((or (null? L) (null? (cdr L))) '())
		; remove last from remaining
		(else (cons (car L) (remove-last (cdr L))))))

(define (rid L)
	(cond ((or (null? L) (null? (cdr L))) "length is less than 2")
		; remove last from remaing 
		(else (remove-last (cdr L)))))
; (rid '(1 2 3 4))

; this is helper function to check list is ascending or not
(define (is-ascenging? L)
	; if list is null or only on element
	(cond ((or (null? L) (null? (cdr L))) #t)
		; if 1st number is greater than 2nd return false
		((> (car L) (cadr L)) #f)
		; else iterate to remaining list
		(else (is-ascenging? (cdr L)))))

; to check list is descending or not
(define (is-descending? L)
	; if list is null or only on element
	(cond ((or (null? L) (null? (cdr L))) #t)
		; if 1st number is less than 2nd return false
		((< (car L) (cadr L)) #f)
		; else iterate to remaining list
		(else (is-descending? (cdr L)))))


(define (order? L)
	(cond ((is-ascenging? L) "ascending")
		((is-descending? L) "descending")
		(else "mixed")))






; this is helper function to check list is ascending or not
(define (is-ascenging? L)
; if list is null or only on element
(cond ((or (null? L) (null? (cdr L))) #t)
; if 1st number is greater than 2nd return false
((> (car L) (cadr L)) #f)
; else iterate to remaining list
(else (is-ascenging? (cdr L)))))

; to check list is descending or not
(define (is-descending? L)
; if list is null or only on element
(cond ((or (null? L) (null? (cdr L))) #t)
; if 1st number is less than 2nd return false
((< (car L) (cadr L)) #f)
; else iterate to remaining list
(else (is-descending? (cdr L)))))


(define (order? L)
(cond ((is-ascenging? L) "ascending")
((is-descending? L) "descending")
(else "mixed")))