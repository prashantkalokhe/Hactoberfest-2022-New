import React from "react";
import { Link } from 'react-router-dom'

const NavBar = () => {
    return ( <
        div >
        <
        nav >
        <
        h3 >
        News Report <
        /h3> <
        ul className = "nav-links" >
        <
        Link to = '/' >
        <
        li > Home < /li> <
        /Link> <
        /ul> <
        /nav> <
        /div>
    );
}



export default NavBar