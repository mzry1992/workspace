const
        n = 4;
        m = 2*n-1;
        max = 10000;
type
        node = record
                code:char;
                w:integer;
                parent,lchild,rchild:0..m;
                end;
        htree = array[1..m] of node;
type
        codetype = record
                bit:array[1..n] of integer;
                sp:1..n;
                ch:char;
                end;
        codes = array[1..n] of codetype;
var
        i,j,i1,p1,p2,small1,small2:integer;
        p:1..n;
        cd:codetype;
        ht:htree;
        cha:array['A'..'Z'] of integer;
        ch1:char;
        bm:codes;
procedure createhfm(var ht:htree);
begin
        for i := 1 to m do
        begin
                ht[i].lchild := 0;
                ht[i].rchild := 0;
                ht[i].parent := 0;
        end;
        for i := n+1 to m do
        begin
                p1 := 0;        p2 := 0;        small1 := max;  small2 := max;
                for j := 1 to i-1 do
                begin
                        if ht[j].parent = 0 then
                        if ht[j].w < small1 then
                        begin
                                small2 := small1;       small1 := ht[j].w;      p2 := p1;       p1 := j;
                        end
                        else
                        if ht[j].w <= small2 then
                        begin
                                small2 := ht[j].w;      p2 := j;
                        end;
                end;
                ht[p1].parent := i;
                ht[p2].parent := i;
                ht[i].lchild := p1;
                ht[i].rchild := p2;
                ht[i].w := ht[p1].w+ht[p2].w;
        end;
end;
procedure hcode(var bm:codes;ht:htree);
begin
        for i := 1 to n do
        for j := 1 to n do      bm[i].bit[j] := 0;
        for i := 1 to n do
        begin
                cd.sp := n;
                for j := 1 to n do cd.bit[j] := 0;
                i1 := i;
                p:=ht[i].parent;
                while p <> 0 do
                begin
                        if ht[p].lchild = i1 then
                                cd.bit[cd.sp] := 0
                        else
                                cd.bit[cd.sp] := 1;
                        cd.sp := cd.sp-1;
                        i1 := p;
                        p := ht[p].parent;
                end;
                bm[i].bit := cd.bit;
                bm[i].sp := cd.sp+1;
        end;
end;

begin
        for ch1 := 'A' to 'Z' do        cha[ch1] := 0;
        read(ch1);
        while ch1 <> '#' do
        begin
                inc(cha[ch1]);
                read(ch1);
        end;
        ch1 := 'A';
        i := 0;
        while ch1 <= 'Z' do
        begin
                if cha[ch1] > 0 then
                begin
                        inc(i);
                        ht[i].w := cha[ch1];
                        ht[i].code := ch1;
                        bm[i].ch := ch1;
                end;
                ch1 := succ(ch1);
        end;
        createhfm(ht);
        hcode(bm,ht);
        for i := 1 to n do
        begin
                write(bm[i].ch,':');
                for j := bm[i].sp to n do       write(bm[i].bit[j]);
                writeln;
        end;
end.