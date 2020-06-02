/*jshint esversion: 6 */
class PCB {
    constructor(name, pri, rou, ct, nt, cou, state, next) {
        //进程标识符
        this.name = name;
        //进程优先数
        this.priod = pri;
        //进程时间轮转时间片
        this.round = rou;
        //进程占用CPU时间
        this.cpuTime = ct;
        //进程到完成还要的时间
        this.needTime = nt;
        //计数器
        this.count = cou;
        //进程的状态
        this.state = state;
        //链指针
        this.next = next;
    }
    


}

var run;
var finish;
var ready = new PCB();
var tail;

var processPool = [];


function runOneProcess() {
    run = ready;
    run.state = "Running";
    ready = ready.next;
}

function buildProcess(obj) {
    obj.forEach(el=>{
        let proc = new PCB(el.name,el.pri,el.rou,el.ct,el.nt,el.cou,el.state,el.next);
        
    });
}

