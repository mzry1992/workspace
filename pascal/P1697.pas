var
        mp:array[1..200,1..200] of 0..2;
        n,m,q,i,j,k,x,y,l1,l2,tot:longint;
        st,order:string;
procedure       error;//报错处理
begin
        writeln('There must be something wrong...');
        halt;
end;
begin
        fillchar(mp,sizeof(mp),0);
        readln(n,m,q);
        for i := 1 to n do      mp[i,i] := 1;
        for i := 1 to m do
        begin
                readln(st); //为了对付一些像 __l1____p_l2____ 的数据而生!
                st := st+' ';
                x := 1;
                while st[x] = ' ' do inc(x);
                inc(x);
                y := x;
                while st[y] in ['0'..'9'] do inc(y);
                val(copy(st,x,y-x),l1);
                while st[y] = ' ' do inc(y);
                order := st[y];
                inc(y);
                x := y;
                while st[x] = ' ' do inc(x);
                inc(x);
                y := x;
                while st[y] in ['0'..'9'] do inc(y);
                val(copy(st,x,y-x),l2);
                if order = 'p' then
                begin
                        if (mp[l1,l2] = 2) or (mp[l2,l1] = 2) then      error;
                        mp[l1,l2] := 1;
                        mp[l2,l1] := 1;
                end;
                if order = 'v' then
                begin
                        if (mp[l1,l2] = 1) or (mp[l2,l1] = 1) then      error;
                        mp[l1,l2] := 2;
                        mp[l1,l2] := 2;
                end;
        end;
        for k := 1 to n do//WS的传递包
        for i := 1 to n do
        for j := 1 to n do
        begin
                if (mp[i,k] = 1) and (mp[k,j] = 1) then
                begin
                        if (mp[i,j] = 2) or (mp[j,i] = 2) then error;
                        mp[i,j] := 1;
                        mp[j,i] := 1;
                end;
                if (mp[i,k] = 2) and (mp[k,j] = 2) then
                begin
                        if (mp[i,j] = 2) or (mp[j,i] = 2) then error;
                        mp[i,j] := 1;
                        mp[j,i] := 1;
                end;
                if (mp[i,k] = 1) and (mp[k,j] = 2) then
                begin
                        if (mp[i,j] = 1) or (mp[j,i] = 1) then error;
                        mp[i,j] := 2;
                        mp[j,i] := 2;
                end;
                if (mp[i,k] = 2) and (mp[k,j] = 1) then
                begin
                        if (mp[i,j] = 1) or (mp[j,i] = 1) then error;
                        mp[i,j] := 2;
                        mp[j,i] := 2;
                end;
        end;
        tot := 0;
        for i := 1 to n-1 do
        for j := i+1 to n do
        if mp[i,j] = 1 then inc(tot); //WS的Task1
        writeln(tot);
        for i := 1 to q do
        begin
                readln(st);//还是WS的输入
                st := st+' ';
                x := 1;
                while st[x] = ' ' do inc(x);
                inc(x);
                y := x;
                while st[y] in ['0'..'9'] do inc(y);
                val(copy(st,x,y-x),l1);
                while st[y] = ' ' do inc(y);
                inc(y);
                x := y;
                while st[y] in ['0'..'9'] do inc(y);
                val(copy(st,x,y-x),l2); //WS的输出
                if mp[l1,l2] = 0 then   writeln('No idea.');
                if mp[l1,l2] = 1 then   writeln('Parallel.');
                if mp[l1,l2] = 2 then   writeln('Vertical.');
        end;
end.
