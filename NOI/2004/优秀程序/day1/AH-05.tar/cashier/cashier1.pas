{$R+,Q+,S+}
Const
    InFile     = 'cashier.in';
    OutFile    = 'cashier1.out';
    Limit      = 21000;

Type
    Tdata      = array[1..Limit] of longint;

Var
    data       : Tdata;
    tot , N ,
    min , Left : longint;

procedure Ins(key : longint);
var
    i          : longint;
begin
    if key < min
      then inc(left)
      else begin
               inc(tot); i := tot;
               while (i > 1) and (data[i - 1] > key) do
                 begin
                     data[i] := data[i - 1];
                     dec(i);
                 end;
               data[i] := key;
           end;
end;

procedure maintain;
var
    i , k      : longint;
begin
    i := 0;
    while (i < tot) and (data[i + 1] < min) do inc(i);
    for k := i + 1 to tot do data[k - i] := data[k];
    dec(tot , i);
    inc(left , i);
end;

procedure main;
var
    j ,
    i , K      : longint;
    ch         : char;
begin
    assign(INPUT , InFile); ReSet(INPUT);
    assign(OUTPUT , OutFile); ReWrite(OUTPUT);
      readln(N , min); tot := 0; Left := 0;
      for i := 1 to N do
        begin
            readln(ch , K);
            case ch of
              'I'             : Ins(K);
              'A'             : for j := 1 to tot do inc(data[j] , K);
              'S'             : begin
                                    for j := 1 to tot do dec(data[j] , K);
                                    maintain;
                                end;
              'F'             : if K > tot
                                  then writeln(-1)
                                  else writeln(data[tot - K + 1]);
            end;
        end;
      writeln(left);
    Close(OUTPUT);
    Close(INPUT);
end;

Begin
    main;
End.
