import React from 'react';
import CsvUpload from './CsvUpload';
import Button from '@mui/material/Button';
import {ButtonGroup} from '@mui/material';
// import { makeStyles } from '@mui/styles';
import Box from '@mui/material/Box';
import TextField from '@mui/material/TextField';
import ChangeText from './ChangeText';
// import { useEffect, useState } from 'react';


function Contents() {

    // const useStyles = makeStyles( (theme) => ({
    //     root : {flexGrow : 1 },
    //     title : { flexGrow : 1 }
    // }) );

    // const classes = useStyles()

    const onChange = () => {}

    const [value, setValue] = React.useState();

    const handleChange = (event) => {
        setValue(event.target.value);
    };

    return (
    <div>
        <div>
            <h3 align='center'>블로그 컨텐츠 마케팅 플랫폼, <strong>볼테페이스</strong></h3>
            <Box container justifyContent="space-between" alignItems="center" sx={{ display: 'flex'}}>
                   <item sx={{ flexGrow: 1 }}>👇변환시킬 문장을 입력하세요😊</item>    
                    <ButtonGroup>
                        <Button id="mybutton" variant="contained" onClick={
                            ChangeText( value , CsvUpload.data) }>
                        변환</Button>
                        <Button disabled onClick={onChange}>복사</Button>
                    </ButtonGroup>
            </Box>
            <br/>
            <Box>
                <TextField
                    placeholder="안녕하세요. 반갑습니다."
                    fullWidth ="fullWidth"
                    label="입력창"
                    multiline
                    maxRows={30}
                    value={value}
                    onChange={handleChange}
                    variant="outlined"
                    
                />
            </Box>
        </div>
    
        <div>
            <CsvUpload />
        </div>
    
    </div>    
    );
}

export default Contents;