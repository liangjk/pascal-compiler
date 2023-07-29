program gcd;

var a,b,c:integer;

function gcd(x,y:integer;) : integer;
	var tmp;
	function min (m,n:integer;) :integer;
		begin
		if(m<n)then begin min:=m; end
		else begin min:=n; end;
		end;
	begin
		if(y=0)then
			begin
			gcd:=x;
			end
		else
			begin
			write(x);
			write(' ');
			writeln(y);
			write(' ');
			tmp:=min(x,y);
			writeln(tmp);
			gcd:=gcd(y,x mod y);
			end;
	end;

begin
read(a);
read(b);
c:=gcd(a,b);
writeln(c);
end.
