LL BinarySearch1(vector<LL> Arr, int N, LL X)
{
    if (X <= Arr[0])
        return Arr[0];
    if (X >= Arr[N - 1])
        return Arr[N - 1];
 
    int l = 0, r = N, mid = 0;
    mid = (l + r) / 2;
    LL CurrentNearest=Arr[l];
    LL dist = abs(CurrentNearest-X);
    while (l < r) {
        mid = (l + r) / 2;
        //printl(Arr[mid]);
        if (Arr[mid] == X){
            CurrentNearest=Arr[mid];
            break;
        }
        if (dist>abs(Arr[mid]-X)&&X>Arr[mid]){
            dist=abs(Arr[mid]-X);
            CurrentNearest=Arr[mid];  
        }
        if (X < Arr[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return CurrentNearest;
}
LL BinarySearch2(vector<LL> Arr, int N, LL X)
{
    if (X <= Arr[0])
        return Arr[0];
    if (X >= Arr[N - 1])
        return Arr[N - 1];
 
    int l = 0, r = N, mid = 0;
    mid = (l + r) / 2;
    LL CurrentNearest=Arr[N-1];
    LL dist = abs(CurrentNearest-X);
    while (l < r) {
        mid = (l + r) / 2;
        if (Arr[mid] == X){
            CurrentNearest=Arr[mid];
            return CurrentNearest;
        }
        if (dist>abs(Arr[mid]-X)&&X<Arr[mid]){
            dist=abs(Arr[mid]-X);
            CurrentNearest=Arr[mid];
            
        }
        if (X < Arr[mid]) {
            if (abs(CurrentNearest-X)>abs(Arr[mid]-X)){
                CurrentNearest=Arr[mid];
            }
            r = mid;
        } else {
            if (abs(CurrentNearest-X)==abs(Arr[mid]-X)){
                
                if (CurrentNearest<Arr[mid]){
                    CurrentNearest=Arr[mid];
                }
            }
            l = mid + 1;
        }
    }
    return CurrentNearest;
}