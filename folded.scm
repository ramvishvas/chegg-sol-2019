(define (foldl-335 op default-element lst)
	; if lst is null return default-element
	(cond ((null? lst) default-element)
		(else 
			; else update defaault value with recursive call
			(foldl-335 op (op default-element (car lst)) 
				(cdr lst)
			)
		)
	)
)

; (foldl-335 + 0 '(1 2 3 4))
; (foldl-335 * 1 '(1 2 3 4))