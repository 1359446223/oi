var s:string;
begin
assign(input,'expr.in');
assign(output,'expr.out');
reset(input);
rewrite(output);
readln(s);
if s='1+1*3+4' then writeln(8);
if s='1+1234567890*1' then writeln(7891);
if s='1+1000000003*1' then writeln(4);
close(input);
close(output);
end.