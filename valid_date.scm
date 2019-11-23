;  this will return true (#t) if year is leap year
;  else false (#f)
(define (leap_year? year)
	; if not number
	(cond ((not (integer? year)) #f)
		; else part
		(else 
			(or 
				(and 
					(equal? (remainder year 4) 0)
					(not (equal? (remainder year 100) 0))
				)
				(equal? (remainder year 400) 0)
			)
		)
	)
)

; (leap_year? 1700)
; (leap_year? 1800)
; (leap_year? 1900)
; (leap_year? 1600)
; (leap_year? 2000)

(define (valid_date? y m day)
	(cond ((and (integer? y) (integer? m) (integer? day))
				; validation of y, m, d
				(cond ((and (>= y 1) (and (>= m 1) (<= m 12)) (and (>= day 1) (<= day 31)))
						; check is m = 2
							(cond ((equal? m 2) 
										;; check is year is leap year
										(cond ((leap_year? y) (and (>= day 1) (<= day 29)))
											; if y is not leap year
											(else  (and (>= day 1) (<= day 28)))
										)
									)
								; check is m even
								((equal? (remainder m 2) 0) (and (>= day 1) (<= day 30)))
								; if m is odd
								(else (and (>= day 1) (<= day 31)))
							)
						)
					(else #f)
				)
			)
			(else #f)
	)
)

; (valid_date? 2014 10 3) → #t
; (valid_date? 2016 2 29) → #t
; (valid_date? -3000 14 87) → #f
; (valid_date? "2019" "September" "7th") → #f