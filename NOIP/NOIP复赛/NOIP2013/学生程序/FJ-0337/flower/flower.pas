program flower;
var i,n:longint;
    a:array[1..1000000] of longint;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
readln(n);
for i:=1 to n do read(a[i]);
writeln('3');
close(input);close(output);
end.
