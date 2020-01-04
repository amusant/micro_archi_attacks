function exponent(b, e, m)
begin
	x ← 1
	for i ← |e| −1 downto 0 do
		x ← x^2
		x ← x mod m
		if (ei = 1) then
			x ← xb
			x ← x mod m
 		endif
 	done
return x
end
