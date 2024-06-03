
function run_wasm(){

    var buscado = document.querySelector("#elemento").value;


    const worker_secuencial = new Worker('worker_secuencial.js');
    worker_secuencial.postMessage({ cmd: buscado});

    worker_secuencial.onmessage = function(e){
        if(e.data.cmd == -1){
            document.querySelector("#ret")
                .innerHTML += `El elemento buscado no se encuentra en el arreglo<br/>`
        }else{
            document.querySelector("#ret")
            .innerHTML += `El elemento buscado secuencialmente esta en la pocision => ${e.data.cmd} del arreglo<br/>`;
        }  
    }

    const worker_binario = new Worker('worker_binario.js');
    worker_binario.postMessage({ cmd: buscado});

    worker_binario.onmessage = function(e){
        if(e.data.cmd == -1){
            document.querySelector("#ret")
                .innerHTML += `El elemento buscado no se encuentra en el arreglo<br/>`
        }else{
            document.querySelector("#ret")
            .innerHTML += `El elemento buscado por binario esta en la pocision => ${e.data.cmd} del arreglo<br/>`;
        }  
    }
    
}