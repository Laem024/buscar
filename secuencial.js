export function run_secuencial(){
    WebAssembly.instantiateStreaming(
        fetch("buscar.wasm"),
        {}
    ).then(result => {
        var buscado = document.querySelector("#elemento").value;

        var resultado_Secuencial = result.instance.exports.Secuencial(buscado);
        
        console.log(resultado_Secuencial);

        if(resultado_Secuencial == -1){
            document.querySelector("#ret")
                .innerHTML += `El elemento buscado no se encuentra en el arreglo<br/>`
        }else{
            document.querySelector("#ret")
            .innerHTML += `El elemento buscado secuencialmente esta en la pocision => ${resultado_Secuencial} del arreglo<br/>`;
        }  
    })
}
