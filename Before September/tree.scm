(define T
	'(13
		(5
			(1 () ())
			(8 ()
				(9 () ())))
		(22
			(17 () ())
			(25 () ()))))


(define (height T)
	; if tree is empty
	(cond ((null? T) 0)
		; return max of left and right tree
		(else (max (+ 1 (height (cadr T))) (+ 1 (height (caddr T)))))))

(define (postorder T)
	; return '() if tree is empty
	(cond ((null? T) '())
		; append root element at last with postorder of left tree and right tree
		(else (append (append (postorder (cadr T)) (postorder (caddr T))) (list (car T))))))