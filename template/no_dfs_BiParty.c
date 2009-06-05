int Bipartite(bool vc [][MAX],int nv1,int nv2) {
    int i, j, x, n;
    int q[MAX], prev[MAX], qs, qe;
    int vm1[MAX], vm2[MAX];

    n = 0;
    for( i = 0; i < nv1; i++ )
        vm1[i] = -1;
    for( i = 0; i < nv2; i++ )
        vm2[i] = -1;
    for( i = 0; i < nv1; i++ ) {
        for( j = 0; j < nv2; j++ )
            prev[j] = -2;
        qs = qe = 0;
        for( j = 0; j < nv2; j++ )
            if( vc[i][j] ) {
                prev[j] = -1;
                q[qe++] = j;
            }
        while( qs < qe ) {
            x = q[qs];
            if( vm2[x] == -1 )
                break;
            qs++;
            for( j = 0; j < nv2; j++ )
                if( prev[j] == -2 && vc[vm2[x]][j] ) {
                    prev[j] = x;
                    q[qe++] = j;
                }
        }
        if( qs == qe )
            continue;
        while( prev[x] > -1 ) {
            vm1[vm2[prev[x]]] = x;
            vm2[x] = vm2[prev[x]];
            x = prev[x];
        }
        vm2[x] = i;
        vm1[i] = x;
        n++;
    }
    return n;
}
