(define  (convert temp x y) 
	(cond ((and (real? temp) 
				(or (equal? "C" x) (equal? "F" x) (equal? "K" x))
				(or (equal? "C" y) (equal? "F" y) (equal? "K" y)))
			(cond 
				((and (equal? "C" x) (equal? "F" y)) (+ (* temp 1.8) 32))
				((and (equal? "C" x) (equal? "K" y)) (+ temp 273.15))
				((and (equal? "F" x) (equal? "C" y)) (/ (- temp 32) 1.8))
				((and (equal? "F" x) (equal? "K" y)) (+ (/ (- temp 32) 1.8) 273.15))
				((and (equal? "K" x) (equal? "C" y)) (- temp 273.15))
				((and (equal? "K" x) (equal? "F" y)) (+ (* (- temp 273.15) 1.8) 32))
			))
		(else "Could not convert from apples to oranges")
	)
)