; get i th index element
(define (my-list-ref L i)
	; check if L is null or  i < 0 or i > size of L then return ""
    (cond ((or (null? L) (< i 0)) "")
        ((equal? 0 i) (car L)) 
        (else (my-list-ref (cdr L) (- i 1)))))

; (my-list-ref (list "a" "b" "c") 0)
; (my-list-ref (list "a" "b" "c") 2)

; this is helper function of find
(define (find-helper s pattern index)
	; check if len of s < len of pattern 
	(cond ((< (string-length s) (string-length pattern)) -1)
		; if match found return index
		((equal? (substring s 0 (string-length pattern)) pattern)  index)
		; else increse index and call function for match
		(else (find-helper (substring s 1) pattern (+ 1 index)))))

(define (find s pattern)
	(cond ((or (null? pattern) (< (string-length s) (string-length pattern))) -1)
		(else (find-helper s pattern 0))))


; (find "one fish two fish red fish blue fish" "fish")
; (find "a haystack" "needle")
; (find "abcabcabc" "ab")
