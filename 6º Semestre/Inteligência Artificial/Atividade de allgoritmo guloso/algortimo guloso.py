def busca_gulosa(no,A,h,linhas,colunas):
    s=[]
    s.append(no)
    aux = []
    melhor_distancia=999999
    n = 0
    i=0
    j=0
    while len(s) > 0:
        melhor_distancia = 9999999
        i = 0
        j = 0
        while i<len(s):
            while j<linhas:
                if h[j][0] == s[i]:
                    if melhor_distancia > h[j][2]:
                        melhor_distancia = h[j][2]
                        n = s[i]
                j += 1
            i += 1
            
        if n == A:
            return n
        else:
            i=0
            j=0
            while j<linhas:
                if h[j][0] == n:
                    s.append(h[j][1])
                j += 1
            while i<len(s):
                if s[i] == n:
                    s.remove(n)
                i += 1


adja_pesos=[[0,2,2],
            [0,1,2],
            [1,2,3],
            [2,3,4],
            [3,4,1],
            [4,4,0]]
printar = "Elemento encontrado {}"
print(printar.format(busca_gulosa(1,4,adja_pesos,6,3)))                 
                        
                        
                        
                        
    