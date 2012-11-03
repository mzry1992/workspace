{
    $Id: gplunit.pt,v 1.2 2002/09/07 15:40:47 peter Exp 2009/10/17 17:37:18 peter Exp $
    This file is part of GaoJingDu
    Copyright (c) 2009 by Kissy (Mu Zi Ri Yun)



    See the file COPYING.FPC, included in this distribution,
    for details about the copyright.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

 **********************************************************************}
Unit GaoJingDu;

Interface

Const
        MaxLong = 1000;

Type
        GJDNum = Record
                z,x:array[0..MaxLong] of integer;
        end;


Implementation

End.
{
  $Log: gplunit.pt,v $
  Revision 1.2  2002/09/07 15:40:47  peter
    * old logs removed and tabs fixed

}


