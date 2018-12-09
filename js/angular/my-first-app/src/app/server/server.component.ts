import { Component } from '@angular/core';

@Component({
    selector: 'app-server',
    templateUrl: './server.component.html',
    styles: [`.online{
        color : white
    }`],
})

export class ServerComponent {
    serverId =  10;
    serverStatus = 'offline';

    getServerStatus(){
        this.serverStatus = Math.random() > 0.5 ? 'online' : 'offline';
        return this.serverStatus;
    }

    getColor(){
        return this.serverStatus === 'online' ? 'green' : 'red';
    }
}

