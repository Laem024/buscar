export function run_binario(){
    WebAssembly.instantiateStreaming(
        fetch("buscar.wasm"),
        {}
    ).then(result => {
        var buscado = document.querySelector("#elemento").value;

        var resultado_Binario = result.instance.exports.Binario(buscado);
        
        
        console.log(resultado_Binario);

        if(resultado_Binario == -1){
            document.querySelector("#ret")
                .innerHTML += `El elemento buscado no se encuentra en el arreglo<br/>`
        }else{
            document.querySelector("#ret")
            .innerHTML += `El elemento buscado por binario esta en la pocision => ${resultado_Binario} del arreglo <br/>`;
        }  
    })
}