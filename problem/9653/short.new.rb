s=' ';[4,10,2,3,4,5,0,3,2,5,2,3,2,1,2,3,2,2,2,0,4,4,2,2,2,2,3,2,2,5,0,7,2,1,2,1,9,1,2,3,2,-1,8,2,2,1,2,5,2,1,2,4,6,0,-1,2,2,2,2,2,3,3,4,5,4,6,-1,2,2,2,2,2,2,2,1,2,3,2,2,2,2,2,-1,2,1,4,1,2,1,2,3,2,2,5,4,4,0,1,3,2,3,1,9,1,2,2,2,6,2,0,2,2,2,2,2,2,5,2,1,2,3,8,0].each{|i|print(i==0?(s='8';"\n"):i==-1?(s=' ';"\n"):s*i);s=s==' '?'8':' '}
