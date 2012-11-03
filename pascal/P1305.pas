const
        number:set of char = ['0'..'9'];
        op:set of char = ['+','-','*','(',')'];
        charr:set of char = ['a'..'z','A'..'Z'];
type
        numtype = record
                total:longint;
                xian:array[1..200] of string;
                xishu:array[1..200] of longint;
        end;
var
        st:string;
        sp:array[1..200] of char;
        sn:array[1..200] of numtype;
        tp,tn,l,i,t,n:longint;
        tmp:string;
function        cancal(ch:char):boolean;
begin
        if (ch = '#') or (ch = ')') then exit(true);
        if (sp[tp] = '*') and (ch in ['+','-']) then exit(true);
        if (sp[tp] in ['+','-']) and (ch in ['+','-']) then exit(true);
        exit(true);
end;
function        jia(a,b:numtype):numtype;
begin
        exit(a);
end;
function        jian(a,b:numtype):numtype;
begin
        exit(a);
end;
function        chen(a,b:numtype):numtype;
begin
        exit(a);
end;
procedure       cal;
begin
        case sp[tp] of
                '+' :   sn[tn-1] := jia(sn[tn-1],sn[tn]);
                '-' :   sn[tn-1] := jian(sn[tn-1],sn[tn]);
                '*' :   sn[tn-1] := chen(sn[tn-1],sn[tn]);
        end;
        dec(tn);
        dec(tp);
end;
procedure       outpu(a:numtype);
var
        i:longint;
begin
        for i := 1 to a.total do
        begin
                if a.xishu[i] > 0 then
                begin
                        if i > 1 then write('+');
                        write(a.xishu[i],a.xian[i]);
                end;
                if a.xishu[i] < 0 then
                begin
                        write(a.xishu[i],a.xian[i]);
                end;
        end;
end;
begin
        readln(st);
        st := st+'#';
        l := length(st);
        tn := 0;
        tp := 1;
        sp[1] := '#';
        t := 1;
        repeat
                if (st[t] in number) or (st[t] in charr) then
                begin
                        n := 0;
                        if st[t] in number then
                        repeat
                                n := n*10+ord(st[t])-48;
                                inc(t);
                        until not (st[t] in number);
                        tmp := '';
                        if st[t] in charr then
                        repeat
                                tmp := tmp+st[t];
                                inc(t);
                        until not (st[t] in charr);
                        inc(tn);
                        sn[tn].total := 1;
                        sn[tn].xian[1] := tmp;
                        sn[tn].xishu[1] := n;
                end
                else
                begin
                        if (st[t] = '(') or not cancal(st[t]) then
                        begin
                                inc(tp);
                                sp[tp] := st[t];
                                inc(t);
                        end
                        else
                        begin
                                if st[t] = ')' then
                                begin
                                        while sp[tp] <> '(' do cal;
                                        dec(tp);
                                        inc(t);
                                end
                                else    cal;
                        end;
                end;
        until (st[t] = '#') and (sp[tp] = '#');
        outpu(sn[1]);
end.


