def busca_em_largura(no,valor,lista):
    s = []
    s.append(no)
    i=0
    
    while s[i] != valor:
        for elemento in lista:
            if elemento.get('pai') == s[i]:
                s.append(elemento.get('valor'))
        i = i + 1
        del s[i]
        if i >= len(lista):
            print("valor não encontrado")
            break
    if i < len(lista):
        print("valor encontrado")
     
valores = [{'valor':1,'pai':0},{'valor':2,'pai':1},{'valor':3,'pai':1},
           {'valor':4,'pai':2},{'valor':5,'pai':2},{'valor':6,'pai':3},]

busca_em_largura(valores[0].get('valor'),5,valores)
