var n,m:longint;
begin
assign(input,'level.in');
assign(output,'level.out');
reset(input);
rewrite(output);
  readln(n,m);
  writeln(m);
close(input);
close(output);
end.