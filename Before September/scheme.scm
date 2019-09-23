(define (water-weight D L K)
	(cond ((or (equal? D 0) (equal? L 0)) 0)
		((equal? K #t) (* 3.14159 (/ D 24) L 62.4))
		(else (* 3.14159 (/ D 24) L 62.08))
	)
)

 ; (water-weight 100 0 #t)
 ; (water-weight 100 0 #t)
 ; (water-weight 100 0 #f)
 ; (water-weight 100 1 #f)
 ; (water-weight 24 1 #f)

(define (classify f)
	(cond ((and (>= f 328.6) (< f 2009)) "UHF")
			((and (>= f 30) (< f 328.6)) "VHF")
			((and (>= f 3) (< f 30)) "HF")
			((and (>= f 0.3) (< f 3)) "MF")
			((and (>= f 0.03) (< f 0.3)) "LF")
			((and (>= f 0.01) (< f 0.03)) "VLF")
			(else "NOT VALID INPUT")
	)
)

; (classify 0.012)

(define (paycheck type num rate gift)
	; if hourly employee
	(cond ((equal? type #t) (- (+ (* num rate) num (* 0.5 (- num 40))) gift))
		; Commissionedd employee
		(else (cond ((< num 500) (- (* num 0.015) gift))
					((< num 1000) (- (*b num 0.03) gift))
					(else (- (* num 0.05)) gift)
			  )
		)
	)
)

; (paycheck #t 4800 2.5 10)