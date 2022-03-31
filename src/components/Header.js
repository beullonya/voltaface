import React from 'react';
import { Button, AppBar, Toolbar, ButtonGroup } from '@mui/material';
import { makeStyles } from '@mui/styles';
import { ReactComponent as Logo } from '../assets/VolteString.svg';
// import "./components/Header.css";
import {Link} from 'react-router-dom';


function Header() {

    const useStyles = makeStyles( (theme) => ({
        root : {flexGrow : 1 },
        title : { flexGrow : 1 }
    }) );

    const classes = useStyles()

    return (
        <div className={classes.root}>
            <AppBar position="static" style={{ background: '#FFBC00' , color: 'black' }}>
                <Toolbar>
                    <h3 className={classes.title} align='left'><Logo width="150" height="40" /></h3>
                    <ButtonGroup >
                        <Button variant="contained" style={{ background: '#FFBC00' , color: 'black' }}  >
                        <Link to="/login"
                        style={{textDecoration: 'none',color: 'black'}} >
                            로그인</Link></Button>
                        <Button variant="contained"
                        style={{ background: '#FFBC00' , color: 'black' }}>
                        <Link to="/signup"
                        style={{textDecoration: 'none',color: 'black' }}>
                            가입하기</Link></Button>
                    </ButtonGroup>
                </Toolbar>
            </AppBar>
            <br/>
        </div>         
    );
}

export default Header;